`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 01:37:31
// Design Name: 
// Module Name: adder_subtractor_4bits
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


module adder_subtractor_4bits (s, cout, a, b, k);
input [3:0] a, b;
input k;
output [3:0] s;
output cout;

wire [3:0]n;

xor XOR0(n[0],b[0], k);
xor XOR1(n[1],b[1], k);
xor XOR2(n[2],b[2], k);
xor XOR3(n[3],b[3], k);


four_bit_adder FBA(s, cout, a, n, k);

endmodule
