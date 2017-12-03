class MyCalendar:

    def __init__(self):
        self.booking = []
        self.overlaps = []
        self.res = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """

        for x, y in self.overlaps:
            if not (
                (start < x and end <= x)
            or (start >= y and end >  y)
            ):
                self.res.append([])
                return False
        
        for x, y in self.booking:
            if not (
                (start < x and end <= x)
            or (start >= y and end >  y)
            ):
                self.overlaps.append([max(x, start), min(y, end)])

        self.booking.append([start, end])
        print("Booking", self.booking)
        print("Overlaps", self.overlaps)
        self.res.append([start, end])
        return True


obj = MyCalendar()

lst = [[],[10,20],[15,25],[20,30]]

for x in lst:
    if x:
        obj.book(x[0], x[1])
    else:
        obj.res.append([])

print(obj.res)