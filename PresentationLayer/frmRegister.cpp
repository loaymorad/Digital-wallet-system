#include "frmRegister.h"
#include "frmSignIn.h"

namespace PresentationLayer {
    System::Void frmRegister::lnkSignIn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        this->Close();
        parentForm->Show();
    }

    System::Void frmRegister::frmRegister_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
        if (this->Modal == false) {
            parentForm->Show();
        }
    }
}