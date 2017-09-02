#include<stdio.h>
#include<errno.h>
#include<modbus/modbus.h>

int main()
{
    modbus_t* mb;
    uint16_t tab_reg[32];

    mb = modbus_new_tcp("127.0.0.1",1502); //as a master(client socket)
    modbus_set_slave(mb,1); // need to set slave number against modbusPalGUI
    if (modbus_connect(mb) == -1)
    {
        printf("connection error");
        modbus_free(mb);
        return 0;
    }

    //modbus_read_input_registers(mb,0,1,tab_reg);
    if (modbus_read_registers(mb,0,10,tab_reg) == -1)
    {
        printf("failed: %s\n", modbus_strerror(errno)); 
        modbus_free(mb);
        return 0;
    }
    //scanf("");
    int i=0;
    for (i=0;i<10;i++)
    {
        printf("%d\n",tab_reg[i]);
    }
    //printf("hello world");
    modbus_free(mb);
    return 0;
}