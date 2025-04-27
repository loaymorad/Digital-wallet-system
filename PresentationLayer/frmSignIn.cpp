#include "frmSignIn.h"
#include "frmRegister.h"

using namespace System;
using namespace PresentationLayer;
using namespace System::Windows::Forms;

namespace PresentationLayer {
    System::Void frmSignIn::lnkRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        this->Hide();
        frmRegister^ registerForm = gcnew frmRegister(this);
        registerForm->Show();
    }
}

[STAThread]
int main(array<System::String^>^ args)
{
    // Enable visual styles
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the application with the SignIn form
    frmSignIn^ signInForm = gcnew frmSignIn();
    Application::Run(signInForm);

    return 0;
}