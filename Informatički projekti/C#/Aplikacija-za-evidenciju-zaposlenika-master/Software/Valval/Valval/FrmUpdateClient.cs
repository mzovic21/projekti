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
    public partial class FrmUpdateClient : Form {
        public FrmUpdateClient(int id) {
            InitializeComponent();
            txtId.Text=id.ToString();
            Client client=ClientRepository.GetClient(id);
            txtFirstName.Text = client.FirstName.ToString();
            txtLastName.Text = client.LastName.ToString();
            txtLocation.Text = client.Location.ToString();
            txtTypeOfService.Text = client.TypeOfService.ToString();
            txtContact.Text = client.Contact.ToString();
        }
        
        private void btnBack_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnUpdate_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            string firstName = txtFirstName.Text;
            string lastName = txtLastName.Text;
            string location = txtLocation.Text;
            string contact = txtContact.Text;
            string typeOfService = txtTypeOfService.Text;
            ClientRepository.UpdateClient( id, firstName, lastName, location, contact, typeOfService);
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();

        }

        private void FrmUpdateClient_Load(object sender, EventArgs e) {
            ShowClient();
        }

        private void ShowClient() {
            

        }

        private void btnBack1_Click(object sender, EventArgs e) {
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void btnUpdate1_Click(object sender, EventArgs e) {
            int id;
            int.TryParse(txtId.Text, out id);
            string firstName = txtFirstName.Text;
            string lastName = txtLastName.Text;
            string location = txtLocation.Text;
            string contact = txtContact.Text;
            string typeOfService = txtTypeOfService.Text;
            ClientRepository.UpdateClient(id, firstName, lastName, location, contact, typeOfService);
            FrmClients frmClients = new FrmClients();
            Hide();
            frmClients.ShowDialog();
            Close();
        }

        private void txtTypeOfService_TextChanged(object sender, EventArgs e) {

        }

        private void txtId_TextChanged(object sender, EventArgs e) {

        }

        private void lblId_Click(object sender, EventArgs e) {

        }

        private void txtContact_TextChanged(object sender, EventArgs e) {

        }

        private void txtLocation_TextChanged(object sender, EventArgs e) {

        }

        private void txtLastName_TextChanged(object sender, EventArgs e) {

        }

        private void txtFirstName_TextChanged(object sender, EventArgs e) {

        }

        private void lblContact_Click(object sender, EventArgs e) {

        }

        private void lblLocation_Click(object sender, EventArgs e) {

        }

        private void lblTypeOfService_Click(object sender, EventArgs e) {

        }

        private void lblLastName_Click(object sender, EventArgs e) {

        }

        private void lblFirstName_Click(object sender, EventArgs e) {

        }

        private void panel1_Paint(object sender, PaintEventArgs e) {

        }
    }
}
