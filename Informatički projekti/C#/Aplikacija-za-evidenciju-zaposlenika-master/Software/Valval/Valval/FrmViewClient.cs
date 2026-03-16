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
    public partial class FrmViewClient : Form {
        public FrmViewClient(int id) {
            InitializeComponent();
            txtId.Text = id.ToString();
            Client client = ClientRepository.GetClient(id);
            txtFirstName.Text = client.FirstName.ToString();
            txtLastName.Text = client.LastName.ToString();
            txtLocation.Text = client.Location.ToString();
            txtTypeOfService.Text = client.TypeOfService.ToString();
            txtContact.Text = client.Contact.ToString();
        }

        private void btnBack1_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void FrmViewClient_Load(object sender, EventArgs e) {

        }
    }
}
