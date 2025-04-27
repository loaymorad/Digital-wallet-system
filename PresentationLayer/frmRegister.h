#pragma once
namespace PresentationLayer {

	// Forward declaration
	ref class frmSignIn;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Forward declaration
	ref class LoginForm;

	/// <summary>
	/// Summary for frmRegister
	/// </summary>
	public ref class frmRegister : public System::Windows::Forms::Form
	{
	public:
		frmRegister(Form^ loginForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			parentForm = loginForm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegister()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::LinkLabel^ lnkSignIn;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txbPassword;
	private: System::Windows::Forms::TextBox^ txbUsername;
	private: System::Windows::Forms::Label^ label1;
	private: Form^ parentForm;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmRegister::typeid));
			this->lnkSignIn = (gcnew System::Windows::Forms::LinkLabel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbPassword = (gcnew System::Windows::Forms::TextBox());
			this->txbUsername = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lnkSignIn
			// 
			this->lnkSignIn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lnkSignIn->AutoSize = true;
			this->lnkSignIn->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 12));
			this->lnkSignIn->LinkColor = System::Drawing::Color::Cyan;
			this->lnkSignIn->Location = System::Drawing::Point(182, 504);
			this->lnkSignIn->Name = L"lnkSignIn";
			this->lnkSignIn->Size = System::Drawing::Size(270, 28);
			this->lnkSignIn->TabIndex = 26;
			this->lnkSignIn->TabStop = true;
			this->lnkSignIn->Text = L"Already have a wallet\? Sign in";
			this->lnkSignIn->VisitedLinkColor = System::Drawing::Color::Cyan;
			this->lnkSignIn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &frmRegister::lnkSignIn_LinkClicked);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->label4->Location = System::Drawing::Point(152, 201);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(327, 28);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Register to create your digital wallet";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(271, 21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(103, 94);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 24;
			this->pictureBox1->TabStop = false;
			// 
			// btnLogin
			// 
			this->btnLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(195)));
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 14, System::Drawing::FontStyle::Bold));
			this->btnLogin->Location = System::Drawing::Point(81, 436);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(459, 45);
			this->btnLogin->TabIndex = 23;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(89, 354);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 28);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Password:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(75, 291);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 28);
			this->label2->TabIndex = 21;
			this->label2->Text = L"User Name:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txbPassword
			// 
			this->txbPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->txbPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->txbPassword->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 12));
			this->txbPassword->ForeColor = System::Drawing::Color::White;
			this->txbPassword->Location = System::Drawing::Point(193, 351);
			this->txbPassword->Multiline = true;
			this->txbPassword->Name = L"txbPassword";
			this->txbPassword->Size = System::Drawing::Size(347, 34);
			this->txbPassword->TabIndex = 20;
			this->txbPassword->UseSystemPasswordChar = true;
			// 
			// txbUsername
			// 
			this->txbUsername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->txbUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->txbUsername->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 12));
			this->txbUsername->ForeColor = System::Drawing::Color::White;
			this->txbUsername->Location = System::Drawing::Point(193, 288);
			this->txbUsername->Multiline = true;
			this->txbUsername->Name = L"txbUsername";
			this->txbUsername->Size = System::Drawing::Size(347, 34);
			this->txbUsername->TabIndex = 19;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(76, 129);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(481, 62);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Create Digital Wallet";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// frmRegister
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->ClientSize = System::Drawing::Size(632, 578);
			this->Controls->Add(this->lnkSignIn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txbPassword);
			this->Controls->Add(this->txbUsername);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"frmRegister";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmRegister::frmRegister_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lnkSignIn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void frmRegister_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
 };
}
