SELECT ingredient_type, SUM(total_order) AS total_order
FROM first_half AS F
INNER JOIN icecream_info AS I
ON F.flavor = I.flavor
GROUP BY ingredient_type
ORDER BY total_order;