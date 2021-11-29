`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 01:44:09
// Design Name: 
// Module Name: full_adder
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


module fulladder (s, cout, a, b, cin);
   input a, b, cin;
   output s, cout;

   //internal signals 
   wire s1, d1, d2;

   //Instantiate the half adders 
    halfadder    HA1 (s1, d1, a, b); 
    halfadder    HA2 (s, d2, s1, cin);
    or U3(cout, d2, d1);

endmodule