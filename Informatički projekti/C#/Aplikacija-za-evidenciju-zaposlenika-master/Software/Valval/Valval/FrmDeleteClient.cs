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
    public partial class FrmDeleteClient : Form {
        public FrmDeleteClient() {
            InitializeComponent();
        }

        private void btnDelete_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            ClientRepository.DeleteClient(id);

            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnBack_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnBack1_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnDelete1_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            ClientRepository.DeleteClient(id);

            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void FrmDeleteClient_Load(object sender, EventArgs e) {

        }
    }
}
