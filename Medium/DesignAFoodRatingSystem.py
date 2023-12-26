class FoodRatings:
    """
    Design a food rating system that can do the following:

    - Modify the rating of a food item listed in the system.
    - Return the highest-rated food item for a type of cuisine in the system.

    Implement the FoodRatings class:

    - FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes
      the system. The food items are described by foods, cuisines and ratings,
      all of which have a length of n.
        - foods[i] is the name of the ith food,
        - cuisines[i] is the type of cuisine of the ith food, and
        - ratings[i] is the initial rating of the ith food.
    - void changeRating(String food, int newRating) Changes the rating of the
      food item with the name food.
    - String highestRated(String cuisine) Returns the name of the food item that
      has the highest rating for the given type of cuisine. If there is a tie,
      return the item with the lexicographically smaller name.

    Note that a string x is lexicographically smaller than string y if x comes before
    y in dictionary order, that is, either x is a prefix of y, or if i is the first
    position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.
    """

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # Dictionary of all foods, their cuisine and ratings, with food = [cuisine, rating]
        self.menu = {}
        self.cuisine_choices = set(cuisines)

        # Dictionary of the best rating per cuisine, with cuisine = [food, rating]
        self.cuisine_ratings = {}
        self.best_cuisine = {}

        # Populate the dictionaries
        for index, food in enumerate(foods):
            # Add the food to the menu dictionary
            self.menu[food] = [cuisines[index], ratings[index]]

            # Add the food to the cuisine_ratings dictionary
            if cuisines[index] not in self.cuisine_ratings:
                self.cuisine_ratings[cuisines[index]] = {}
            self.cuisine_ratings[cuisines[index]][food] = ratings[index]
        self.findHighestRating()

    def changeRating(self, food: str, newRating: int) -> None:
        if food in self.menu:
            cuisine = self.menu[food][0]
            self.menu[food][1] = newRating
            self.cuisine_ratings[cuisine][food] = newRating
        if newRating > self.best_cuisine[cuisine][1] or (
            newRating == self.best_cuisine[cuisine][1]
            and self.best_cuisine[cuisine][0] > food
        ):
            self.best_cuisine[cuisine] = [food, newRating]
        elif (
            food == self.best_cuisine[cuisine][0]
            and newRating > self.best_cuisine[cuisine][1]
        ):
            self.best_cuisine[cuisine] = [food, newRating]
        elif (
            food == self.best_cuisine[cuisine][0]
            and newRating < self.best_cuisine[cuisine][1]
        ):
            self.findHighestRating()

    def highestRated(self, cuisine: str) -> str:
        return self.best_cuisine[cuisine][0]

    def findHighestRating(self) -> None:
        for cuisine_type in self.cuisine_choices:
            best_value = None
            max_rating = -1
            for food, rating in self.cuisine_ratings[cuisine_type].items():
                if max_rating < rating or (max_rating == rating and food < best_value):
                    best_value = food
                    max_rating = rating
            self.best_cuisine[cuisine_type] = [best_value, max_rating]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
