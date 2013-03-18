require 'rubygems'  
require 'serialport' # use Kernel::require on windows, works better.  
  
#params for serial port  
port_str = "/dev/tty.usbmodem1411"  #may be different for you  
baud_rate = 9600  
data_bits = 8  
stop_bits = 1  
parity = SerialPort::NONE  

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

#just read forever  
while true do  
  sp_char = sp.getc  
  if sp_char  
    printf("%c", sp_char)  
  end  
end

