/*2.1*/
select top 3 title_id, title, pubdate, min(royalty) as  NhuanButThapNhat
from titles
where month(pubdate) = 6
group by title_id, title, pubdate
order by NhuanButThapNhat asc;
/*2.2*/
select top 5 a.au_id, a.au_fname, a.au_lname, count(ta.title_id) as SoLuongSach
from authors a inner join titleauthor ta on a.au_id = ta.au_id inner join titles t on ta.title_id = t.title_id
group by a.au_id, a.au_fname, a.au_lname
order by SoLuongSach desc;
/*2.3*/
select s.ord_num, st.city, st.state, st.stor_address, st.stor_id, st.stor_name, st.zip
from stores st inner join sales s on st.stor_id = s.stor_id
where ord_num like '%5%'
/*2.4*/
select top 3 st.stor_id, st.stor_name, max(s.ord_date) as NgayBanHangMuonNhat
from stores st inner join sales s on st.stor_id = s.stor_id
group by st.stor_id, st.stor_name
order by NgayBanHangMuonNhat desc;
/*2.5*/
select t.title, au_lname, au_fname, t.ytd_sales, a.state
from stores st inner join sales s on st.stor_id = s.stor_id inner join titles t on s.title_id = t.title_id inner join titleauthor tl on t.title_id = tl.title_id inner join authors a on tl.au_id = a.au_id
where t.ytd_sales > 500 and t.ytd_sales < 5000 and a.state = 'CA';
/*2.6*/
/* Mã sách null */
/*2.7*/
/*ko làm đc*/
