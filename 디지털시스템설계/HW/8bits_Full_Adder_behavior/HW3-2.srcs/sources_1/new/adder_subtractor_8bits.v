`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 02:41:35
// Design Name: 
// Module Name: adder_subtractor_8bits
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


module adder_subtractor_8bits(s,cout,a,b,k);
    input [7:0] a,b;
    input k;
    output [7:0] s;
    output cout;
    reg [7:0]s;
    reg cout;
    
    always @ (a or b or k)
    begin
      if(k)
        begin
          s = a - b;
   if( a < b)
      cout = 1'b0;
   else
            cout = 1'b1;
        end
      else
        begin
          s = a + b;
          if( a + b > 9'b011111111 )
            cout = 1'b1;
          else
            cout = 1'b0;
        end
    end
endmodule
