SELECT cart_id
FROM (SELECT DISTINCT cart_id, name
      FROM cart_products
      WHERE name IN ("Milk", "Yogurt")) AS c
GROUP BY cart_id
HAVING COUNT(*) = 2
ORDER BY cart_id;