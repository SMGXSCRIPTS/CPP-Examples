#include <iostream>
#include <cstring>

int main(int ARGUEMENT_COUNT, char* ARGUEMENT_LIST[])
{
        for (int FINDER_COUNTER = 1; FINDER_COUNTER < ARGUEMENT_COUNT; ++FINDER_COUNTER)
        {
                if (strcmp(ARGUEMENT_LIST[FINDER_COUNTER], "--test2") == 0)
                {
                        if (FINDER_COUNTER + 1 < ARGUEMENT_COUNT)
                        {
                                if (strcmp(ARGUEMENT_LIST[FINDER_COUNTER + 1], "FUN") == 0)
                                {
                                        FINDER_COUNTER += 1;
                                        std::cout << "test2" << std::endl;
                                }
                                else
                                {
                                        std::cerr << "Arguement --test2 Does Not Support: " << ARGUEMENT_LIST[FINDER_COUNTER + 1] << std::endl;
                                        return 1;
                                }
                        }
                        else
                        {
                                std::cerr << "No Arguement Value For --test2 Supplied" << std::endl;
                                return 1;
                        }
                }
                else if (strcmp(ARGUEMENT_LIST[FINDER_COUNTER], "--test1") == 0)
                {
                        std::cout << "test1" << std::endl;
                }
                else
                {
                        std::cerr << "Arguement Not Recogized: " << ARGUEMENT_LIST[FINDER_COUNTER] << std::endl;
                        return 1;
                }
        }
        return 0;
}
