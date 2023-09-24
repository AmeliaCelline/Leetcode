class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        //if there is no negative integer, then just square everything normally
        if (nums[0] >= 0){
            for (auto i = nums.begin(); i!= nums.end(); i++){
                *i = pow(*i,2);
            }
            return nums;
        }
        //if there is negative integer
        else{
            //okay so the best way to do this would be using two pointers.
            //i will call these 2 pointers left and right pointer, where left pointer will point to the negative integer right beside the positive integer, and the right pointer will point to the first positive integer.
            int leftPointer, rightPointer = 0;
            for(auto i : nums){
                if(i < 0) {
                    rightPointer += 1;
                }
                else break;
            }


            //create a vector to store all the answers
            vector <int> answer(nums.size());
            int counter = 0;

            //no positive integer, so just iterate the array from the last index to the beginning, square them, then put them into vector "answer".
            if(rightPointer >= nums.size()){
                for (auto i = nums.rbegin(); i!= nums.rend(); i++){
                    answer[counter] = pow(*i,2);
                    counter += 1;
                }
                return answer;
            }

            leftPointer = rightPointer - 1;

            //these 2 poitners will transverse through the array.
            //if the squared value pointed by left pointer is bigger or equal than the squared value pointed by right pointer then put the element that is pointed by the right pointer to vector "answer". Move the right pointer to the right by one. 
            //if the squared value pointer by left pointer is less than the squared value pointed by the right pointer, then add the element pointed by the left pointer into answer and move the left pointer to the left. (to the left because the squared value of the negative integer will become bigger if move to the left)

            while(counter < nums.size()){
                int leftValueSquared = pow(nums[leftPointer], 2), rightValueSquared = pow(nums[rightPointer],2);
                if(leftValueSquared < rightValueSquared){
                    answer[counter] = leftValueSquared;
                    leftPointer -= 1; 
                    //if no more negative integer, then just squared the remaining positive integers and add them to answer.
                    if(leftPointer < 0){
                        while(rightPointer < nums.size()){
                            counter += 1;
                            answer[counter] = pow( nums[rightPointer],2);
                            rightPointer += 1;
                        }
                        break;
                    }
                }
                else{
                    answer[counter] = rightValueSquared;
                    rightPointer += 1; 
                    //if no more positive integer, then just squared the remaining negative integers and add them to answer.
                    if(rightPointer >= nums.size()){
                        while(leftPointer >= 0){
                            counter += 1;
                            answer[counter] = pow(nums[leftPointer],2);
                            leftPointer -= 1;
                        }
                        break;
                    }
                }

                counter += 1;
            }


            return answer;  
        }

    }
};