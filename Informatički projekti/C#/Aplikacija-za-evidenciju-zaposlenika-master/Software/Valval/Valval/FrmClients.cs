using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Valval.Models;
using Valval.Repositories;

namespace Valval {
    public partial class FrmClients : Form {
        public FrmClients() {
            InitializeComponent();
        }

        private void FrmClients_Load(object sender, EventArgs e) {
            ShowClients();
        }

        private void ShowClients() {
            List<Client> clients = ClientRepository.GetClients();
            dgvClients.DataSource = clients;

            dgvClients.Columns["Id"].DisplayIndex = 0;
            dgvClients.Columns["FirstName"].DisplayIndex = 1;
            dgvClients.Columns["LastName"].DisplayIndex = 2;
            dgvClients.Columns["TypeOfService"].DisplayIndex = 3;
            dgvClients.Columns["Location"].DisplayIndex = 4;
            dgvClients.Columns["Contact"].DisplayIndex = 5;
        }

        private void btnBack_Click(object sender, EventArgs e) {
            FrmHome frmHome = new FrmHome();
            Hide();
            frmHome.ShowDialog();
            Close();
        }

        private void dgvClients_CellContentClick(object sender, DataGridViewCellEventArgs e) {

        }

        private void btnAdd_Click(object sender, EventArgs e) {
            FrmAddClient frmAdd = new FrmAddClient();
            Hide();
            frmAdd.ShowDialog();
            Close();
        }

        private void btnDelete_Click(object sender, EventArgs e) {
            FrmDeleteClient frmDelete = new FrmDeleteClient();
            Hide();
            frmDelete.ShowDialog();
            Close();
        }

        private void btnUpdate_Click(object sender, EventArgs e) {
            FrmGetClient frmGet = new FrmGetClient();
            Hide();
            frmGet.ShowDialog();
            Close();
        }

        private void btnView_Click(object sender, EventArgs e) {
            FrmGetClientData frmGetData = new FrmGetClientData();
            Hide();
            frmGetData.ShowDialog();
            Close();
        }
    }
}
