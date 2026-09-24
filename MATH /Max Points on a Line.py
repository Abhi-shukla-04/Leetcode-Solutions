class Solution:
    def maxPoints(self, points):
        n = len(points)

        if n <= 2:
            return n

        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        ans = 0

        for i in range(n):
            slopes = {}
            duplicates = 0
            local_max = 0

            x1, y1 = points[i]

            for j in range(i + 1, n):
                x2, y2 = points[j]

                dx = x2 - x1
                dy = y2 - y1

                # Duplicate points
                if dx == 0 and dy == 0:
                    duplicates += 1
                    continue

                # Reduce slope
                g = gcd(abs(dx), abs(dy))
                dx //= g
                dy //= g

                # Normalize slope
                if dx < 0:
                    dx = -dx
                    dy = -dy

                # Vertical line
                if dx == 0:
                    dy = 1

                # Horizontal line
                if dy == 0:
                    dx = 1

                slope = (dy, dx)

                slopes[slope] = slopes.get(slope, 0) + 1

                local_max = max(local_max, slopes[slope])

            ans = max(ans, local_max + duplicates + 1)

        return ans
