SELECT APNT_NO, PT_NAME, PT_NO, a.MCDP_CD, DR_NAME, APNT_YMD
FROM (SELECT APNT_NO, MDDR_ID, APNT_CNCL_YN, APNT_YMD, PT_NAME, a.PT_NO, a.MCDP_CD
      FROM appointment AS a
      INNER JOIN patient AS p
      ON a.pt_no = p.pt_no) AS a
INNER JOIN doctor AS d
ON a.mddr_id = d.dr_id
WHERE DATE_FORMAT(apnt_ymd, "%Y-%m-%d") = "2022-04-13" AND apnt_cncl_yn = "N" AND a.mcdp_cd = "CS"
ORDER BY apnt_ymd;