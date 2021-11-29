`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 02:47:53
// Design Name: 
// Module Name: tb_adder_subtractor_8bits
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


module tb_adder_subtractor_8bits();

reg [7:0] a,b;
reg k;
wire [7:0] s;
wire cout;
adder_subtractor_8bits a2 (.s(s),.cout(cout),.a(a),.b(b),.k(k));

initial 
    begin
#5
    a[0]= 0; b[0] = 0; k = 0;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 1;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 1;
    a[7]= 1; b[7] = 1;
#5
    a[0]= 0; b[0] = 0; k = 1;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 1;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 1;
    a[7]= 1; b[7] = 1;
#5
    a[0]= 1; b[0] = 0; k = 0;
    a[1]= 0; b[1] = 0;
    a[2]= 1; b[2] = 0;
    a[3]= 1; b[3] = 0;
    a[4]= 1; b[4] = 0;
    a[5]= 0; b[5] = 1;
    a[6]= 0; b[6] = 0;
    a[7]= 1; b[7] = 0;
#5
    a[0]= 0; b[0] = 0; k = 1;
    a[1]= 0; b[1] = 0;
    a[2]= 1; b[2] = 0;
    a[3]= 1; b[3] = 1;
    a[4]= 1; b[4] = 1;
    a[5]= 1; b[5] = 0;
    a[6]= 1; b[6] = 0;
    a[7]= 0; b[7] = 0;
    
    end
endmodule