class StartStationAndStartTimepair{
    
    String startStation;
    int startTime;

    public StartStationAndStartTimepair(String startStation, int startTime) {
        this.startStation = startStation;
        this.startTime = startTime;
    }

}

class StartStationAndEndStationPair{
    String startStation;
    String endStation;
    public StartStationAndEndStationPair(String startStation, String endStation) {
        this.startStation = startStation;
        this.endStation = endStation;
    }
    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((endStation == null) ? 0 : endStation.hashCode());
        result = prime * result + ((startStation == null) ? 0 : startStation.hashCode());
        return result;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        StartStationAndEndStationPair other = (StartStationAndEndStationPair) obj;
        if (endStation == null) {
            if (other.endStation != null)
                return false;
        } else if (!endStation.equals(other.endStation))
            return false;
        if (startStation == null) {
            if (other.startStation != null)
                return false;
        } else if (!startStation.equals(other.startStation))
            return false;
        return true;
    }

    
}

class AverageAndNumberOfObsPair{
    
    double averageTime;
    int numberOfObs;
    
    public AverageAndNumberOfObsPair(double averageTime, int numberOfObs) {
        this.averageTime = averageTime;
        this.numberOfObs = numberOfObs;
    }

    public double getAverageTime() {
        return averageTime;
    }

    public void setAverageTime(double averageTime) {
        this.averageTime = averageTime;
    }

    public int getNumberOfObs() {
        return numberOfObs;
    }

    public void setNumberOfObs(int numberOfObs) {
        this.numberOfObs = numberOfObs;
    }
}

public class UndergroundSystem {

    

    private HashMap<Integer,StartStationAndStartTimepair> hm1 = new HashMap<>();
    private HashMap<StartStationAndEndStationPair,AverageAndNumberOfObsPair> hm2 = new HashMap<>();

    public UndergroundSystem() {
        
    }
    
    public void checkIn(int id, String stationName, int t) {
        hm1.put(id, new StartStationAndStartTimepair(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        
        if(hm1.containsKey(id))
        {

            int timeTaken = t - hm1.get(id).startTime;
            String endStation = stationName;

            StartStationAndEndStationPair sp = new StartStationAndEndStationPair(hm1.get(id).startStation, endStation);

            if(hm2.containsKey(sp))
            {
                AverageAndNumberOfObsPair averageAndNumberOfObsPair = hm2.get(sp);
                double oldAvg = averageAndNumberOfObsPair.averageTime;
                int oldObs = averageAndNumberOfObsPair.numberOfObs;
                double newAvg = ((oldAvg * oldObs) + timeTaken) / (oldObs + 1 );

                averageAndNumberOfObsPair.setAverageTime(newAvg);
                averageAndNumberOfObsPair.setNumberOfObs(oldObs + 1);
            }else{
                
                hm2.put(sp, new AverageAndNumberOfObsPair((double)timeTaken, 1));

            }


        }
    }
    
    public double getAverageTime(String startStation, String endStation) {
        
        StartStationAndEndStationPair startStationAndEndStationPair = new StartStationAndEndStationPair(startStation, endStation);

        return hm2.get(startStationAndEndStationPair).averageTime;

    }
}


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */