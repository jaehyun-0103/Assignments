package org.tukorea.club.test;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.tukorea.club.domain.MemberVO;
import org.tukorea.club.persistence.MemberDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = { "file:src/main/webapp/WEB-INF/spring/root-context.xml" })
@Transactional
public class MemberDAOTest {

	@Autowired
	private MemberDAO memberDAO;
	
	@Test
	public void testAdd() throws Exception {
		MemberVO vo = new MemberVO();
		vo.setMemberName("jaehyun");
		vo.setEmail("jaehyun@naver.com");
		vo.setPassword("passwd");
		memberDAO.join(vo);
	}
	
	@Test
	public void testDelete() throws Exception {
		memberDAO.delete(1);
	}
	
	@Test
	public void testSelect() throws Exception {
		MemberVO vo = new MemberVO();
		vo.setEmail("kim@example.com");
		vo.setPassword("1234");
		System.out.println(memberDAO.login(vo));
	}
	
	@Test
	public void testRead() throws Exception {
		MemberVO vo = memberDAO.read(1);
		System.out.println(vo.getMemberId());
		System.out.println(vo.getEmail());
		System.out.println(vo.getPassword());
		System.out.println(vo.getMemberName());
	}
}
