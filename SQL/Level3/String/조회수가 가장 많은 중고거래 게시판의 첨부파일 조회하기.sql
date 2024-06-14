SELECT CONCAT("/home/grep/src/", f.board_id, "/", file_id, file_name, file_ext) AS FILE_PATH
FROM used_goods_board AS b
INNER JOIN used_goods_file AS f
ON b.board_id = f.board_id
WHERE views = (SELECT MAX(views) FROM used_goods_board)
ORDER BY file_id DESC;