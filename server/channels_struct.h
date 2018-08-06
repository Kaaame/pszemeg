enum Ports
{
    pbch_port = 20700,
    dl_sch_port = 20701,
    ul_sch_port = 20702,
    pdcch_port = 20703,
    pucch_port = 20704,
    prach_port = 20705
};

enum Channel_flags
{
    random_access_response
};

struct MIB_MESSAGE
{
    int prach_port;
    int broadcast_port;
    int dl_sch_port;
    int ul_sch_port;
    int pdcch_port;
    int pucch_port;
};

struct DCI_MESSAGE
{
    unsigned char format0_a_flag;
    unsigned char freqency_hooping;
    int riv;
    int mcs;
    unsigned char ndi;
    int tpc;
    int cyclic_shift;
    unsigned char cqi_request;
};