using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void chart1_Click(object sender, EventArgs e)
        {
          
        }

        private void button2_Click(object sender, EventArgs e)
        {

            Thread masterthread;
            masterthread = new Thread(runit);
            masterthread.Start();
            port = new SerialPort(comboBox1.Text, Convert.ToInt32(textBox1.Text));
            port.Open();
        }
        SerialPort port;
        string getvalue;
        void runit()
        {
            while(true)
            {
                try
                {
                    if(port.IsOpen == true)
                    {
                        getvalue = port.ReadLine();
                        int i = 0;
                        if (i == 2)
                        {
                            i = 0;
                        }
                        chart1.Invoke((MethodInvoker)(() => chart1.Series["data1"].Points.AddXY(i,getvalue)));
                        //chart1.Series[0].Points.Add(new System.Windows.Forms.DataVisualization.Charting.DataPoint(i, getvalue));

                        // chart1.ChartAreas[0].AxisY.IsReversed = true;
                        // chart1.ChartAreas[0].AxisY.Crossing = double.MaxValue;
                        i++;
                    }
                }
                catch(Exception ex)
                {

                }
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] Ports = SerialPort.GetPortNames();
            foreach (string Port in Ports)
            {
                comboBox1.Items.Add(Port);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void chart2_Click(object sender, EventArgs e)
        {

        }
    }
    
}
