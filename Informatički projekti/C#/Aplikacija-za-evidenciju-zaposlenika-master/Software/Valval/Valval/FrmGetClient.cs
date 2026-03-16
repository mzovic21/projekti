using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Valval.Repositories;

namespace Valval {
    public partial class FrmGetClient : Form {
        public FrmGetClient() {
            InitializeComponent();
        }

        private void btnBack_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnGet_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            FrmUpdateClient frmUpdate = new FrmUpdateClient(id);
            Hide();
            frmUpdate.ShowDialog();
            Close();
        }

        private void btnBack1_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnGet1_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            FrmUpdateClient frmUpdate = new FrmUpdateClient(id);
            Hide();
            frmUpdate.ShowDialog();
            Close();
        }

        private void FrmGetClient_Load(object sender, EventArgs e) {

        }
    }
}
