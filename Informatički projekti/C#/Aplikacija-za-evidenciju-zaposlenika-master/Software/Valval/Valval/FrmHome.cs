using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Valval {
    public partial class FrmHome : Form {
        public FrmHome() {
            InitializeComponent();
        }

        private void btnEvident_Click(object sender, EventArgs e) {
            FrmLoading frmLoading = new FrmLoading();
            Hide();
            frmLoading.ShowDialog();
            Close();
        }

        private void FrmHome_Load(object sender, EventArgs e) {

        }

        private void lblInfo_Click(object sender, EventArgs e) {

        }
    }
}
