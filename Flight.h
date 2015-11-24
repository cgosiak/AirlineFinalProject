//
// Created by caleb on 11/23/15.
//

#ifndef MYPROGRAM3_AIRPLANE_H
#define MYPROGRAM3_AIRPLANE_H

namespace FinalProject {
    class Flight {
    public:
        Flight();
        void Print_Flight_Name();
        std::string Get_Flight_Name();

    private:
        std::string name_of_flight;
    };
}

#endif //MYPROGRAM3_AIRPLANE_H
