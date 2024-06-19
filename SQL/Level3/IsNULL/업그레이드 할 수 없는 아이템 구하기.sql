SELECT item_id, ITEM_NAME, RARITY
FROM item_info
WHERE item_id NOT IN (SELECT DISTINCT i.item_id
                      FROM item_info AS i
                      INNER JOIN item_tree AS t
                      ON i.item_id = t.parent_item_id)
ORDER BY item_id DESC;