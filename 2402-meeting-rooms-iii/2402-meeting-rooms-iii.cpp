class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        vector<long long> roomAvailableTime(n, 0);
        vector<int> count(n, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            int earliestRoom = 0;
            bool foundUnused = false;

            for (int i = 0; i < n; i++) {
                // Pick the first room that is already free at 'start'
                if (roomAvailableTime[i] <= start) {
                    roomAvailableTime[i] = end;
                    count[i]++;
                    foundUnused = true;
                    break;
                }
                // Keep track of the room that frees up the earliest just in case
                if (roomAvailableTime[i] < roomAvailableTime[earliestRoom]) {
                    earliestRoom = i;
                }
            }

            // If all rooms were busy, delay the meeting using the earliest available room
            if (!foundUnused) {
                roomAvailableTime[earliestRoom] += (end - start);
                count[earliestRoom]++;
            }
        }

        // Return the index of the maximum element in 'count'
        return max_element(count.begin(), count.end()) - count.begin();
    }
};
