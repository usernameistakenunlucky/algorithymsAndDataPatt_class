/*
Using your custom Dijkstra Algorithm (Weighted Graph):

1) Create a class City
   a. std::string mName
   b. Vector2 mPosition

2) Create a class GPS
   a. Vector<City> mCities
   b. WeightedGraph<City, float> mCityGraph
   c. void AddCity(const std::string& name, const Vector2& pos)
      i.  Adds a city to mCities
      ii. Make sure there are no repeats
   d. void ConnectCities(const City& a, const City& b)
      i.   Find the index of each city
      ii.  Use the distance between them as the weight
      iii. Link the cities in mCityGraph
   e. float FindPath(const City& from, const City& to, Vector<const City*>& pathOutput)
      i.   Obtains the path from mCityGraph
      ii.  Sum up the weights for the total road distance
      iii. Returns the result

3) Main flow
   a. Create a GPS system
   b. Populate the GPS with the cities laid out in the diagram below
   c. The units are measured in kilometers
   d. Find and print the path between:
      i.   Vancouver to Cranbrook
      ii.  Prince Rupert to Kelowna
      iii. Fort Nelson to Creston
   e. Assuming the average speed along the roads is 80 km/h
      i. Print the estimated duration to travel each route in (d)
*/