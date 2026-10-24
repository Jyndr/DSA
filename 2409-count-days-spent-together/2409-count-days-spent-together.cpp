class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int arr[] = {0,   31,  59,  90,  120, 151, 181,
                     212, 243, 273, 304, 334, 365};

        int alice_end_day =
            arr[(leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0') - 1] +
            (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

        int alice_start_day =
            arr[(arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0') - 1] +
            (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');

        int bob_end_day =
            arr[(leaveBob[0] - '0') * 10 + (leaveBob[1] - '0') - 1] +
            (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

        int bob_start_day =
            arr[(arriveBob[0] - '0') * 10 + (arriveBob[1] - '0') - 1] +
            (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');

        if (alice_start_day > bob_end_day || bob_start_day > alice_end_day) {
            return 0;
        }

        return min(alice_end_day, bob_end_day) -
               max(alice_start_day, bob_start_day) + 1;
    }
};