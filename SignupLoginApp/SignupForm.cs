using System;
using System.Windows.Forms;

namespace SignupLoginApp
{
    public partial class SignupForm : Form
    {
        public SignupForm()
        {
            InitializeComponent();
        }

        private void btnSignup_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Signup Successful!");
        }
    }
}
