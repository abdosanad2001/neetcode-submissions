class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> taskFreq;
        for(char t: tasks){
            taskFreq[t]++;
        }
        priority_queue<int> max_heap;
        for(auto& pair: taskFreq){
            max_heap.push(pair.second);
        }

        queue<pair<int,int>> q;
        int time=0;
        while(!q.empty() || !max_heap.empty()){
            time++;
            // Si le tas n'est pas vide, 
            //on exécute la tâche la plus fréquente
            if(!max_heap.empty()){
                int cnt=max_heap.top()-1;
                max_heap.pop();
                // Si la tâche doit encore être répétée
                if(cnt>0){
                    q.push({cnt,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                max_heap.push(q.front().first);
                q.pop();
                
            }
        }
        return time;


        

    }
};
