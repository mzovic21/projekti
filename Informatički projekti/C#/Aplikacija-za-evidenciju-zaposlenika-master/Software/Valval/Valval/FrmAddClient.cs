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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Valval {
    public partial class FrmAddClient : Form {
        public FrmAddClient() {
            InitializeComponent();
        }

        private void FrmAdd_Load(object sender, EventArgs e) {

        }

        private void label1_Click(object sender, EventArgs e) {

        }

        private void textBox1_TextChanged(object sender, EventArgs e) {

        }

        private void btnBack_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnAdd_Click(object sender, EventArgs e) {

            int id ;
            int.TryParse(txtId.Text, out id);
            string firstName = txtFirstName.Text;
            string lastName = txtLastName.Text;
            string location = txtLocation.Text;
            string contact = txtContact.Text;
            string typeOfService = txtTypeOfService.Text;

            ClientRepository.AddClient(id, firstName, lastName, location, contact, typeOfService);

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

        private void btnAdd1_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            string firstName = txtFirstName.Text;
            string lastName = txtLastName.Text;
            string location = txtLocation.Text;
            string contact = txtContact.Text;
            string typeOfService = txtTypeOfService.Text;

            ClientRepository.AddClient(id, firstName, lastName, location, contact, typeOfService);

            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void txtLocation_TextChanged(object sender, EventArgs e) {

        }

        private void txtContact_TextChanged(object sender, EventArgs e) {

        }
    }
}
