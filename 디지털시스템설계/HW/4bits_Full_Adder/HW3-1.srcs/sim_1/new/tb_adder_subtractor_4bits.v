`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 01:46:50
// Design Name: 
// Module Name: tb_adder_subtractor_4bits
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_adder_subtractor_4bits();
reg [3:0] a,b;
reg k;
wire [3:0] s;
wire cout;

adder_subtractor_4bits a1 (.s(s), .cout(cout), .a(a), .b(b), .k(k));
initial 
    begin
#5 
     a[0]=1; b[0]=1; k=0;
     a[1]=1; b[1]=1; 
     a[2]=1; b[2]=1;
     a[3]=1; b[3]=1;
#5
     a[0]=0; b[0]=1; k=1;
     a[1]=0; b[1]=1; 
     a[2]=0; b[2]=1;
     a[3]=0; b[3]=1;
#5
     a[0]=0; b[0]=1; k=0;
     a[1]=0; b[1]=1;
     a[2]=1; b[2]=0;
     a[3]=0; b[3]=1;
#5
     a[0]=1; b[0]=0; k=1;
     a[1]=1; b[1]=0; 
     a[2]=1; b[2]=1;
     a[3]=0; b[3]=1;
    end

endmodule