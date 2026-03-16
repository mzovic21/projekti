namespace Valval {
    partial class FrmGetClient {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmGetClient));
            this.btnBack1 = new System.Windows.Forms.Button();
            this.btnGet1 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.lblNewClient = new System.Windows.Forms.Label();
            this.txtId = new System.Windows.Forms.TextBox();
            this.lblId = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnBack1
            // 
            this.btnBack1.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.btnBack1.FlatAppearance.BorderColor = System.Drawing.Color.DodgerBlue;
            this.btnBack1.FlatAppearance.BorderSize = 2;
            this.btnBack1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnBack1.Font = new System.Drawing.Font("Segoe Print", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnBack1.Location = new System.Drawing.Point(41, 232);
            this.btnBack1.Name = "btnBack1";
            this.btnBack1.Size = new System.Drawing.Size(129, 47);
            this.btnBack1.TabIndex = 5;
            this.btnBack1.Text = "Povratak";
            this.btnBack1.UseVisualStyleBackColor = false;
            this.btnBack1.Click += new System.EventHandler(this.btnBack1_Click);
            // 
            // btnGet1
            // 
            this.btnGet1.BackColor = System.Drawing.Color.Yellow;
            this.btnGet1.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnGet1.FlatAppearance.BorderSize = 2;
            this.btnGet1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGet1.Font = new System.Drawing.Font("Segoe Print", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnGet1.Location = new System.Drawing.Point(279, 232);
            this.btnGet1.Name = "btnGet1";
            this.btnGet1.Size = new System.Drawing.Size(205, 47);
            this.btnGet1.TabIndex = 6;
            this.btnGet1.Text = "Dohvati klijenta";
            this.btnGet1.UseVisualStyleBackColor = false;
            this.btnGet1.Click += new System.EventHandler(this.btnGet1_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.LightSkyBlue;
            this.panel1.Controls.Add(this.lblNewClient);
            this.panel1.Location = new System.Drawing.Point(0, 29);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(522, 78);
            this.panel1.TabIndex = 18;
            // 
            // lblNewClient
            // 
            this.lblNewClient.AutoSize = true;
            this.lblNewClient.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblNewClient.Font = new System.Drawing.Font("Segoe Print", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblNewClient.Location = new System.Drawing.Point(88, 7);
            this.lblNewClient.Name = "lblNewClient";
            this.lblNewClient.Size = new System.Drawing.Size(329, 71);
            this.lblNewClient.TabIndex = 10;
            this.lblNewClient.Text = "Odabir klijenta";
            // 
            // txtId
            // 
            this.txtId.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtId.Location = new System.Drawing.Point(205, 162);
            this.txtId.Name = "txtId";
            this.txtId.Size = new System.Drawing.Size(100, 30);
            this.txtId.TabIndex = 20;
            // 
            // lblId
            // 
            this.lblId.AutoSize = true;
            this.lblId.BackColor = System.Drawing.Color.Transparent;
            this.lblId.Font = new System.Drawing.Font("Segoe Print", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblId.Location = new System.Drawing.Point(153, 156);
            this.lblId.Name = "lblId";
            this.lblId.Size = new System.Drawing.Size(46, 40);
            this.lblId.TabIndex = 19;
            this.lblId.Text = "Id:";
            // 
            // FrmGetClient
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(522, 318);
            this.Controls.Add(this.txtId);
            this.Controls.Add(this.lblId);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btnGet1);
            this.Controls.Add(this.btnBack1);
            this.Name = "FrmGetClient";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Dohvaćanje klijenta";
            this.Load += new System.EventHandler(this.FrmGetClient_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnBack1;
        private System.Windows.Forms.Button btnGet1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label lblNewClient;
        private System.Windows.Forms.TextBox txtId;
        private System.Windows.Forms.Label lblId;
    }
}