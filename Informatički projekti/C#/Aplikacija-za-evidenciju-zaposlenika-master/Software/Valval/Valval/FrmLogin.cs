using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

namespace Valval {
    public partial class FrmLogin : Form {

        string username = "test";
        string password = "test";

        public FrmLogin() {
            InitializeComponent();
        }

        private void FrmProba_Load(object sender, EventArgs e) {

        }

        private void btnLogin_Click(object sender, EventArgs e) {
            if (txtUsername.Text == "") {
                MessageBox.Show("Korisničko ime nije uneseno!", "Greška", MessageBoxButtons.OK, MessageBoxIcon.Error);
            } else if (txtPassword.Text == "") {
                MessageBox.Show("Lozinka nije unesena!", "Greška", MessageBoxButtons.OK, MessageBoxIcon.Error);
            } else if (txtUsername.Text != username || txtPassword.Text != password) {
                MessageBox.Show("Neispravni podaci!", "Greška", MessageBoxButtons.OK, MessageBoxIcon.Error);
            } else {
                FrmHome frmHome = new FrmHome();
                Hide();
                frmHome.ShowDialog();
                Close();
            }
        }
    }
}
