`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 05:38:48
// Design Name: 
// Module Name: tb_cal
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


module tb_cal();
reg [7:0] a,b;
reg [1:0] sel;
wire c, aGreaterb, aEqualb, aLessb;
wire [7:0] r;

Calculator cal(.a(a), .b(b), .sel(sel), .c(c), .r(r), .aGreaterb(aGreaterb), .aEqualb(aEqualb), .aLessb(aLessb));

initial 
    begin
#5
    a[0]= 0; b[0] = 0; sel = 2'b00;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 0;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 1;
    a[7]= 1; b[7] = 0;
#5
    a[0]= 0; b[0] = 0; sel = 2'b01;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 0;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 1;
    a[7]= 1; b[7] = 0;
#5
    a[0]= 0; b[0] = 0; sel = 2'b10;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 0;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 1;
    a[7]= 1; b[7] = 0;
#5
    a[0]= 0; b[0] = 0; sel = 2'b11;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 0;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 1;
    a[7]= 1; b[7] = 0;
#5
    a[0]= 0; b[0] = 0; sel = 2'b11;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 0;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 0; b[6] = 0;
    a[7]= 1; b[7] = 1;
#5
    a[0]= 0; b[0] = 0; sel = 2'b11;
    a[1]= 0; b[1] = 0;
    a[2]= 0; b[2] = 0;
    a[3]= 0; b[3] = 0;
    a[4]= 0; b[4] = 0;
    a[5]= 0; b[5] = 0;
    a[6]= 1; b[6] = 0;
    a[7]= 0; b[7] = 1;
    end
endmodule