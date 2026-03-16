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
    public partial class FrmLoading : Form {
        public FrmLoading() {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e) {
            panel2.Width += 3;
            if(panel2.Width >= 534) {
                timer1.Stop();
                FrmClients frmClients = new FrmClients();
                Hide();
                frmClients.ShowDialog();
                Close();
            }
        }

        private void FrmLoading_Load(object sender, EventArgs e) {

        }
    }
}
