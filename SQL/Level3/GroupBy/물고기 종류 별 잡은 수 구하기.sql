SELECT COUNT(1) AS FISH_COUNT, FISH_NAME
FROM (SELECT fish_name
      FROM fish_info AS fi
      INNER JOIN fish_name_info AS fni
      ON fi.fish_type = fni.fish_type) AS fish
GROUP BY fish_name
ORDER BY fish_count DESC;