SELECT ap.APNT_NO, (
    select pt_name
    from PATIENT
    where PT_NO = ap.pt_no
) as PT_NAME, ap.PT_NO, ap.MCDP_CD, (
    select DR_NAME
    from DOCTOR
    where DR_ID = ap.MDDR_ID
) as DR_NAME, ap.APNT_YMD
from APPOINTMENT ap
where date(APNT_YMD) = '2022-04-13' and APNT_CNCL_YN='N' and MCDP_CD='CS'
order by APNT_YMD