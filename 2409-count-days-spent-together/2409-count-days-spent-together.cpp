class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int startA = toDayOfYear(arriveAlice);
        int endA = toDayOfYear(leaveAlice);
        int startB = toDayOfYear(arriveBob);
        int endB = toDayOfYear(leaveBob);

        int overlapStart = std::max(startA, startB);
        int overlapEnd = std::min(endA, endB);

        return std::max(0, overlapEnd - overlapStart + 1);
    }

private:
    
    const std::vector<int> daysInMonths = {31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31};

    int toDayOfYear(const std::string& dateStr) {
        
        int month = std::stoi(dateStr.substr(0, 2));
        int day = std::stoi(dateStr.substr(3, 2));

       
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += daysInMonths[i];
        }

        return dayCount + day;
    }
};
