`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 05:17:13
// Design Name: 
// Module Name: Calculator
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


module Calculator(a, b, sel, c, r, aGreaterb, aEqualb, aLessb);
    input [7:0] a,b;
    input [1:0] sel;
    output [7:0] r;
    output c, aGreaterb = 0, aEqualb = 0, aLessb = 0;
    
    reg [7:0] r;
    reg c,aGreaterb, aEqualb, aLessb;

    always @ (a or b or sel)
    begin
    case(sel)
    2'b00:
        begin
            r = a + b;
            if( a + b > 9'b011111111 )
                c = 1'b1;
            else
                c = 1'b0;
        end
    2'b01:
        begin
            r = a - b;
            if( a < b)
                c = 1'b0;
            else
                c = 1'b1;
        end
    2'b10:
        begin
            r = a ^ b;
            c = 1'b0;
        end
    2'b11:
        begin
            r = 8'b00000000;
            c = 1'b0;
            if(a > b)       {aGreaterb, aEqualb, aLessb} = 3'b100;
            else if(a == b) {aGreaterb, aEqualb, aLessb} = 3'b010;
            else            {aGreaterb, aEqualb, aLessb} = 3'b001;
        end
    endcase
    end
endmodule