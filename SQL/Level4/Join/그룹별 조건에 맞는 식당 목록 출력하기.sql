SELECT MEMBER_NAME, REVIEW_TEXT, DATE_FORMAT(review_date, "%Y-%m-%d") AS REVIEW_DATE
FROM member_profile AS m
INNER JOIN rest_review AS r
ON m.member_id = r.member_id
WHERE r.MEMBER_ID = (SELECT MEMBER_ID
                     FROM rest_review
                     GROUP BY member_id
                     ORDER BY COUNT(1) DESC
                     LIMIT 1)
ORDER BY review_date, review_text;