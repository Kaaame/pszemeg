#include "eNodeB.h"
#include "channels_struct.h"

#include <vector>
#include <iostream>

eNodeB::eNodeB() :
pbch(Ports::pbch_port, 0x75FFFF),
pdcch(Ports::pdcch_port, 0x5FFFFF),
pdsch(Ports::dl_sch_port),
prach(Ports::prach_port)
{
}

void eNodeB::start()
{
    while(true)
    {
        if(this->pbch.get_counter() == 0)
        {
            this->pbch.send_mib();
        }

        if(this->pdcch.get_counter() == 0)
        {
            this->pdcch.send_dci(true);
        }

        this->pdsch.handle_queue(this->ue_queue);

        this->prach.receive_message();
    }
}