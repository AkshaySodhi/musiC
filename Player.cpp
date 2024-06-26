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
	int trackLen; //milisec

	bool trackOpen;
	bool isShuffled;
	bool isPaused;

	std::string currPath;
	std::string currTrack;
	std::vector<std::string> trackList;

	Player():currIndex(-1), trackLen(0), trackOpen(false), isShuffled(false), isPaused(false)
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

	void setTrackLength()
	{
		char lenBuffer[1024] = {};
		mciSendStringA("status track length", lenBuffer, sizeof(lenBuffer), 0);

		trackLen = std::atoi(lenBuffer);
	}

	int getCurrPos()
	{
		char szResponse[1024] = { 0 };
		mciSendStringA("status track position", szResponse, sizeof(szResponse), NULL);

		return std::atoi(szResponse); //milisec
	}

	void playTrack()
	{
		std::string openStr = "open \"" + currPath + "/" + currTrack + "\" alias track";
		if (trackOpen) mciSendStringA("close track", NULL, 0, NULL);

		mciSendStringA(openStr.c_str(), NULL, 0, NULL);
		setTrackLength();
		mciSendStringA("play track", NULL, 0, NULL);

		trackOpen = true;
		isPaused = false;
	}

	void pauseTrack()
	{
		mciSendStringA("pause track", NULL, 0, NULL);
		isPaused = true;
	}

	void resumeTrack()
	{
		mciSendStringA("resume track", NULL, 0, NULL);
		isPaused = false;
	}

	void replayTrack()
	{
		mciSendStringA("play track from 0", NULL, 0, NULL);
		isPaused = false;
	}

	void seekTrack(int time)
	{
		std::string cmd = "play track from " + std::to_string(time);;
		mciSendStringA(cmd.c_str(), NULL, 0, NULL);
	}

	void shuffle()
	{
		isShuffled = !isShuffled;
	}

	bool isPlaying() const 
	{
		char szBuffer[1024]={};
		mciSendStringA("status track mode", szBuffer, sizeof(szBuffer), 0);

		return (memcmp(szBuffer, "playing", 7) == 0);
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