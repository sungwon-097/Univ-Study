`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 01:45:33
// Design Name: 
// Module Name: four_bit_adder
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

module four_bit_adder (s, c4, a, b, c);
   input [3:0] a,b;
   input c;
   output [3:0] s; 
   output c4;
  
  
//Declare intermediate carries
 wire c1, c2, c3;
  
//Instantiate the fulladder 
  fulladder FA0(s[0], c1, a[0], b[0], c);
  fulladder FA1(s[1], c2, a[1], b[1], c1);
  fulladder FA2(s[2], c3, a[2], b[2], c2);
  fulladder FA3(s[3], c4, a[3], b[3], c3);
  
endmodule