#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include<filesystem>

namespace fs = std::filesystem;

//helper fxns
static std::string getFileType(const fs::path& filePath)
{
	std::string extension = filePath.extension().string();

	if (extension == ".wav") return "wav";
	else if (extension == ".mp3") return "mp3";
	return "";
}

class Player
{
public:
	size_t currIndex;

	bool trackOpen;
	bool isShuffled;
	bool isPaused;

	std::string currPath;
	std::string currTrack;
	std::vector<std::string> trackList;

	Player():currIndex(-1),trackOpen(false),isShuffled(false),isPaused(false)
	{
	}

	void generateTrackList()
	{
		trackList.clear();
		//shrink to fit?

		fs::path directoryPath = fs::path(currPath);
		if (fs::is_empty(directoryPath)) return;

		for (const auto& entry : fs::directory_iterator(directoryPath))
		{
			if (fs::is_regular_file(entry.status()))
			{
				std::string fileType = getFileType(entry.path());

				if (fileType == "mp3" || fileType == "wav")
				{
					trackList.push_back(entry.path().filename().string());
				}
			}
		}
	}

	void playTrack()
	{
		std::string openStr = "open \"" + currPath + "/" + currTrack + "\" alias track";
		std::wstring openCmd = std::wstring(openStr.begin(), openStr.end());

		if (trackOpen) mciSendString(TEXT("close track"), NULL, 0, NULL);

		mciSendString(openCmd.c_str(), NULL, 0, NULL);
		mciSendString(TEXT("play track"), NULL, 0, NULL);

		trackOpen = true;
		isPaused = false;
	}

	void pauseTrack()
	{
		mciSendString(TEXT("pause track"), NULL, 0, NULL);
		isPaused = true;
	}

	void resumeTrack()
	{
		mciSendString(TEXT("resume track"), NULL, 0, NULL);
		isPaused = false;
	}

	void replayTrack()
	{
		mciSendString(TEXT("play track from 0"), NULL, 0, NULL);
		isPaused = false;
	}

	void shuffle()
	{
		isShuffled = !isShuffled;
	}

	bool isPlaying() const 
	{
		WCHAR wszBuffer[1024]={};
		mciSendStringW(L"status track mode", wszBuffer, ARRAYSIZE(wszBuffer), 0);

		return (memcmp(wszBuffer, L"playing", 7) == 0);
	}

	bool downloadFile(const std::string& url) const
	{
		std::string command = "ytdl-mp3 -n -o " + currPath + " " + url;

		//int returnCode = WinExec(command.c_str(), SW_HIDE); //deprecated
		int returnCode = system(command.c_str()); //shows console

		if (returnCode!= 0) return false;
		return true;
	}
};