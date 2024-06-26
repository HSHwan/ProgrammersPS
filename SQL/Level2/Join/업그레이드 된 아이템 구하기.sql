SELECT I.ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO AS I INNER JOIN ITEM_TREE AS IT ON I.ITEM_ID = IT.ITEM_ID
WHERE (SELECT RARITY FROM ITEM_INFO WHERE ITEM_ID = IT.PARENT_ITEM_ID) = "RARE"
ORDER BY ITEM_ID DESC