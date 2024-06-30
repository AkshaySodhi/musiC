#pragma once

#include<filesystem>
#include <msclr\marshal_cppstd.h>
#include "Player.cpp";

Player player;

namespace musiC {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std::filesystem;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ textBoxPath;
        System::Windows::Forms::Button^ buttonListFiles;
        System::Windows::Forms::ListBox^ listBoxFiles;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ buttonReplay;

    private: System::Windows::Forms::Button^ buttonPlayPause;



    private: System::Windows::Forms::Button^ buttonPrev;
    private: System::Windows::Forms::Button^ buttonNext;
    private: System::Windows::Forms::Button^ buttonShuffle;
    private: System::Windows::Forms::Button^ buttonDownload;
    private: System::Windows::Forms::Panel^ pnlDownload;
    private: System::Windows::Forms::Button^ btnYtReq;
    private: System::Windows::Forms::TextBox^ textBoxURL;



    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Timer^ timer1;
    private: System::Windows::Forms::TrackBar^ trackBar1;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;



    private: System::ComponentModel::IContainer^ components;

    private:
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
            this->buttonListFiles = (gcnew System::Windows::Forms::Button());
            this->listBoxFiles = (gcnew System::Windows::Forms::ListBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->buttonReplay = (gcnew System::Windows::Forms::Button());
            this->buttonPlayPause = (gcnew System::Windows::Forms::Button());
            this->buttonPrev = (gcnew System::Windows::Forms::Button());
            this->buttonNext = (gcnew System::Windows::Forms::Button());
            this->buttonShuffle = (gcnew System::Windows::Forms::Button());
            this->buttonDownload = (gcnew System::Windows::Forms::Button());
            this->pnlDownload = (gcnew System::Windows::Forms::Panel());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->btnYtReq = (gcnew System::Windows::Forms::Button());
            this->textBoxURL = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->pnlDownload->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
            this->SuspendLayout();
            // 
            // textBoxPath
            // 
            this->textBoxPath->Enabled = false;
            this->textBoxPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->textBoxPath->Location = System::Drawing::Point(56, 18);
            this->textBoxPath->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->textBoxPath->Name = L"textBoxPath";
            this->textBoxPath->Size = System::Drawing::Size(396, 26);
            this->textBoxPath->TabIndex = 0;
            this->textBoxPath->Text = L"Choose directory";
            // 
            // buttonListFiles
            // 
            this->buttonListFiles->AutoSize = true;
            this->buttonListFiles->BackColor = System::Drawing::Color::Transparent;
            this->buttonListFiles->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonListFiles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->buttonListFiles->Location = System::Drawing::Point(460, 16);
            this->buttonListFiles->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->buttonListFiles->Name = L"buttonListFiles";
            this->buttonListFiles->Size = System::Drawing::Size(72, 30);
            this->buttonListFiles->TabIndex = 1;
            this->buttonListFiles->Text = L"Browse";
            this->buttonListFiles->UseVisualStyleBackColor = false;
            this->buttonListFiles->Click += gcnew System::EventHandler(this, &MyForm::buttonListFiles_Click);
            // 
            // listBoxFiles
            // 
            this->listBoxFiles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->listBoxFiles->FormattingEnabled = true;
            this->listBoxFiles->ItemHeight = 20;
            this->listBoxFiles->Location = System::Drawing::Point(13, 63);
            this->listBoxFiles->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->listBoxFiles->Name = L"listBoxFiles";
            this->listBoxFiles->Size = System::Drawing::Size(519, 344);
            this->listBoxFiles->TabIndex = 2;
            this->listBoxFiles->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBoxFiles_SelectedIndexChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 21);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(46, 20);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Path:";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->Location = System::Drawing::Point(114, 499);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(13, 20);
            this->label3->TabIndex = 6;
            this->label3->Text = L" ";
            this->label3->Visible = false;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(8, 498);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(110, 20);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Now Playing:";
            this->label2->Visible = false;
            // 
            // buttonReplay
            // 
            this->buttonReplay->BackColor = System::Drawing::Color::Transparent;
            this->buttonReplay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonReplay.BackgroundImage")));
            this->buttonReplay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->buttonReplay->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonReplay->Location = System::Drawing::Point(207, 421);
            this->buttonReplay->Name = L"buttonReplay";
            this->buttonReplay->Size = System::Drawing::Size(35, 35);
            this->buttonReplay->TabIndex = 7;
            this->buttonReplay->UseVisualStyleBackColor = false;
            this->buttonReplay->Visible = false;
            this->buttonReplay->Click += gcnew System::EventHandler(this, &MyForm::buttonReplay_Click);
            // 
            // buttonPlayPause
            // 
            this->buttonPlayPause->BackColor = System::Drawing::Color::Transparent;
            this->buttonPlayPause->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlayPause.BackgroundImage")));
            this->buttonPlayPause->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->buttonPlayPause->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonPlayPause->Location = System::Drawing::Point(248, 421);
            this->buttonPlayPause->Name = L"buttonPlayPause";
            this->buttonPlayPause->Size = System::Drawing::Size(35, 35);
            this->buttonPlayPause->TabIndex = 8;
            this->buttonPlayPause->UseVisualStyleBackColor = false;
            this->buttonPlayPause->Visible = false;
            this->buttonPlayPause->Click += gcnew System::EventHandler(this, &MyForm::buttonPlayPause_Click);
            // 
            // buttonPrev
            // 
            this->buttonPrev->BackColor = System::Drawing::Color::Transparent;
            this->buttonPrev->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPrev.BackgroundImage")));
            this->buttonPrev->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->buttonPrev->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonPrev->Location = System::Drawing::Point(166, 421);
            this->buttonPrev->Name = L"buttonPrev";
            this->buttonPrev->Size = System::Drawing::Size(35, 35);
            this->buttonPrev->TabIndex = 9;
            this->buttonPrev->UseVisualStyleBackColor = false;
            this->buttonPrev->Visible = false;
            this->buttonPrev->Click += gcnew System::EventHandler(this, &MyForm::buttonPrev_Click);
            // 
            // buttonNext
            // 
            this->buttonNext->BackColor = System::Drawing::Color::Transparent;
            this->buttonNext->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonNext.BackgroundImage")));
            this->buttonNext->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->buttonNext->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonNext->Location = System::Drawing::Point(330, 421);
            this->buttonNext->Name = L"buttonNext";
            this->buttonNext->Size = System::Drawing::Size(35, 35);
            this->buttonNext->TabIndex = 10;
            this->buttonNext->UseVisualStyleBackColor = false;
            this->buttonNext->Visible = false;
            this->buttonNext->Click += gcnew System::EventHandler(this, &MyForm::buttonNext_Click);
            // 
            // buttonShuffle
            // 
            this->buttonShuffle->BackColor = System::Drawing::Color::Transparent;
            this->buttonShuffle->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonShuffle.BackgroundImage")));
            this->buttonShuffle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->buttonShuffle->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonShuffle->Location = System::Drawing::Point(289, 421);
            this->buttonShuffle->Name = L"buttonShuffle";
            this->buttonShuffle->Size = System::Drawing::Size(35, 35);
            this->buttonShuffle->TabIndex = 11;
            this->buttonShuffle->UseVisualStyleBackColor = false;
            this->buttonShuffle->Visible = false;
            this->buttonShuffle->Click += gcnew System::EventHandler(this, &MyForm::buttonShuffle_Click);
            // 
            // buttonDownload
            // 
            this->buttonDownload->BackColor = System::Drawing::Color::Transparent;
            this->buttonDownload->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDownload.BackgroundImage")));
            this->buttonDownload->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->buttonDownload->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonDownload->Location = System::Drawing::Point(497, 421);
            this->buttonDownload->Name = L"buttonDownload";
            this->buttonDownload->Size = System::Drawing::Size(35, 35);
            this->buttonDownload->TabIndex = 12;
            this->buttonDownload->UseVisualStyleBackColor = false;
            this->buttonDownload->Visible = false;
            this->buttonDownload->Click += gcnew System::EventHandler(this, &MyForm::buttonDownload_Click);
            // 
            // pnlDownload
            // 
            this->pnlDownload->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->pnlDownload->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlDownload.BackgroundImage")));
            this->pnlDownload->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->pnlDownload->Controls->Add(this->button1);
            this->pnlDownload->Controls->Add(this->btnYtReq);
            this->pnlDownload->Controls->Add(this->textBoxURL);
            this->pnlDownload->Controls->Add(this->label4);
            this->pnlDownload->Location = System::Drawing::Point(37, 97);
            this->pnlDownload->Name = L"pnlDownload";
            this->pnlDownload->Size = System::Drawing::Size(470, 156);
            this->pnlDownload->TabIndex = 13;
            this->pnlDownload->Visible = false;
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Transparent;
            this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button1->Location = System::Drawing::Point(236, 95);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(102, 26);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Exit";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // btnYtReq
            // 
            this->btnYtReq->BackColor = System::Drawing::Color::Transparent;
            this->btnYtReq->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnYtReq->Location = System::Drawing::Point(127, 95);
            this->btnYtReq->Name = L"btnYtReq";
            this->btnYtReq->Size = System::Drawing::Size(103, 26);
            this->btnYtReq->TabIndex = 2;
            this->btnYtReq->Text = L"Download";
            this->btnYtReq->UseVisualStyleBackColor = false;
            this->btnYtReq->Click += gcnew System::EventHandler(this, &MyForm::btnYtReq_Click);
            // 
            // textBoxURL
            // 
            this->textBoxURL->Location = System::Drawing::Point(42, 63);
            this->textBoxURL->Name = L"textBoxURL";
            this->textBoxURL->Size = System::Drawing::Size(396, 26);
            this->textBoxURL->TabIndex = 1;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Transparent;
            this->label4->Location = System::Drawing::Point(38, 40);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(209, 20);
            this->label4->TabIndex = 0;
            this->label4->Text = L"Enter URL of youtube video:";
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Interval = 200;
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
            // 
            // trackBar1
            // 
            this->trackBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(171)),
                static_cast<System::Int32>(static_cast<System::Byte>(218)));
            this->trackBar1->LargeChange = 1;
            this->trackBar1->Location = System::Drawing::Point(81, 462);
            this->trackBar1->Maximum = 1000;
            this->trackBar1->Name = L"trackBar1";
            this->trackBar1->Size = System::Drawing::Size(371, 45);
            this->trackBar1->TabIndex = 14;
            this->trackBar1->TabStop = false;
            this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
            this->trackBar1->Visible = false;
            this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::Transparent;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label5->Location = System::Drawing::Point(40, 463);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(32, 17);
            this->label5->TabIndex = 15;
            this->label5->Text = L"--:--";
            this->label5->Visible = false;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Transparent;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label6->Location = System::Drawing::Point(451, 463);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(32, 17);
            this->label6->TabIndex = 16;
            this->label6->Text = L"--:--";
            this->label6->Visible = false;
            // 
            // MyForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(724, 522);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->pnlDownload);
            this->Controls->Add(this->buttonDownload);
            this->Controls->Add(this->buttonShuffle);
            this->Controls->Add(this->buttonNext);
            this->Controls->Add(this->buttonPrev);
            this->Controls->Add(this->buttonPlayPause);
            this->Controls->Add(this->buttonReplay);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->listBoxFiles);
            this->Controls->Add(this->buttonListFiles);
            this->Controls->Add(this->textBoxPath);
            this->Controls->Add(this->trackBar1);
            this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"musiC++";
            this->pnlDownload->ResumeLayout(false);
            this->pnlDownload->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void buttonListFiles_Click(System::Object^ sender, System::EventArgs^ e) {
        FolderBrowserDialog^ diag = gcnew FolderBrowserDialog();
        if (diag->ShowDialog() == Windows::Forms::DialogResult::OK)
        {
            textBoxPath->Text = diag->SelectedPath;
            buttonDownload->Show();

            buttonPrev->Show();
            buttonReplay->Show();
            buttonPlayPause->Show();
            buttonShuffle->Show();
            buttonNext->Show();
            trackBar1->Show();
            
            label2->Show();
            label3->Show();
            label5->Show();
            label6->Show();
        }
        else return;

        std::string stdPath = msclr::interop::marshal_as<std::string>(textBoxPath->Text);
        if (player.currPath == stdPath) return;

        player.currPath = stdPath;
        player.generateTrackList();

        listBoxFiles->Items->Clear();
        for (const auto& track : player.trackList)
        {
            String^ fileName = gcnew String(track.c_str());
            listBoxFiles->Items->Add(fileName);
        }

        if (player.trackList.size() == 0) MessageBox::Show("No music files found", "Info.", MessageBoxButtons::OK, MessageBoxIcon::Information);

        ////set height of listBox
       /* int count = listBoxFiles->Items->Count+1;
        if (count > 18) count = 18;
        std::cout << count;
        listBoxFiles->Height = listBoxFiles->ItemHeight * count;*/
    }

    private: System::Void listBoxFiles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxFiles->SelectedIndex < 0) return; 

        player.currIndex = listBoxFiles->SelectedIndex;
        player.currTrack = player.trackList[player.currIndex];
        player.playTrack();

        label3->Text = gcnew String(player.currTrack.c_str());
    }

    private: System::Void buttonReplay_Click(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen)
        {
            player.replayTrack();
        }
    }

    private: System::Void buttonPlayPause_Click(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen)
        {
            if (player.isPaused)
            {
                player.resumeTrack();
            }
            else
            {
                player.pauseTrack();
            }
        }
    }

    private: System::Void buttonPrev_Click(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen)
        {
            if (listBoxFiles->SelectedIndex < 0 || player.trackList.size() < 1) return;

            size_t index = listBoxFiles->SelectedIndex;
            if (index < 0) return;

            index == 0 ? index = player.trackList.size() - 1 : index--;
            listBoxFiles->SelectedIndex = index;
        }
    }

    private: System::Void buttonNext_Click(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen)
        {
            if (listBoxFiles->SelectedIndex < 0 || player.trackList.size()<1) return;

            size_t index = listBoxFiles->SelectedIndex;
            if (player.isShuffled && player.trackList.size() > 1)
            {
                size_t r = rand() % player.trackList.size();
                while (index == r)
                {
                    r = rand() % player.trackList.size();
                }
                index = r;
            }
            else
            {
                index == player.trackList.size() - 1 ? index = 0 : index++;
            }
            listBoxFiles->SelectedIndex = index;
        }
    }

    private: System::Void buttonShuffle_Click(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen)
        {
            player.shuffle();
        }
    }

    private: System::Void buttonDownload_Click(System::Object^ sender, System::EventArgs^ e) {
        textBoxURL->Clear();
        pnlDownload->Show();
    }

    private: System::Void btnYtReq_Click(System::Object^ sender, System::EventArgs^ e) {
        if (player.downloadFile(msclr::interop::marshal_as<std::string>(textBoxURL->Text)))
        {
            player.generateTrackList();

            listBoxFiles->Items->Clear();
            for (const auto& track : player.trackList)
            {
                String^ fileName = gcnew String(track.c_str());
                listBoxFiles->Items->Add(fileName);
            }

            MessageBox::Show("Downloaded Successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            MessageBox::Show("Download Failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        pnlDownload->Hide();
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        pnlDownload->Hide();
    }

    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen && !player.isPaused)
        {
            if (!player.isPlaying())
            {
                buttonNext->PerformClick();
            }

            int currTime = player.getCurrPos(); //milisec
            trackBar1->Value = currTime * 1000 / player.trackLen;

            int currMin = (currTime / 1000) / 60;
            int currSec = (currTime / 1000) % 60;

            int totalMin = (player.trackLen / 1000) / 60;
            int totalSec = (player.trackLen / 1000) % 60;

            label5->Text = String::Format("{00:00}", currMin) + ":" + String::Format("{00:00}", currSec); 
            label6->Text= String::Format("{00:00}", totalMin) + ":" + String::Format("{00:00}", totalSec); //TODO: optimize and name labels
        }
    }
    private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
        if (player.trackOpen)
        {
            //FIX: implement seek
            if (player.isPaused)
            {
                buttonPlayPause->PerformClick();
                player.seekTrack(trackBar1->Value * player.trackLen / 1000);
                buttonPlayPause->PerformClick();
            }
            else
            {
                player.seekTrack(trackBar1->Value * player.trackLen / 1000);
            }
        }
    }
};
}
