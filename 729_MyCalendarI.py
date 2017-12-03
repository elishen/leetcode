class MyCalendar:

    def __init__(self):
        self.booking = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        
        for x in self.booking:
            if not (
                (start < x[0] and end <= x[0])
            or (start >= x[1] and end > x[1])
            ):
                return False
        
        self.booking.append([start, end])
        return True

obj = MyCalendar()

lst = [[],[10,20],[15,25],[20,30]]

for x in lst:
    if x:
        obj.book(x[0], x[1])
    else:
        obj.res.append([])

