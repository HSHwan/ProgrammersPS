SELECT COUNT(CASE WHEN FN.FISH_NAME = "BASS" OR FN.FISH_NAME = "SNAPPER" THEN 1 END) AS FISH_COUNT
FROM FISH_INFO AS F INNER JOIN FISH_NAME_INFO AS FN ON F.FISH_TYPE = FN.FISH_TYPE