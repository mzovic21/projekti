using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Valval {
    public partial class FrmGetClientData : Form {
        public FrmGetClientData() {
            InitializeComponent();
        }

        private void btnGet_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            FrmViewClient frmView = new FrmViewClient(id);
            Hide();
            frmView.ShowDialog();
            Close();
        }

        private void btnBack_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void FrmGetClientData_Load(object sender, EventArgs e) {

        }
    }
}
