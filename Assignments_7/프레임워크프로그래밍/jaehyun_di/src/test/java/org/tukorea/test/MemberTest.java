package org.tukorea.test;

import java.util.List;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.tukorea.di.domain.StudentVO;
import org.tukorea.di.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:/applicationContext.xml")

public class MemberTest {

	@Autowired
	MemberService memberService;

	@Test
	public void testReadMemberList() throws Exception {
		List<StudentVO> list = memberService.readMemberList();
		for (StudentVO svo : list) {
			System.out.println("----------------------------------");
			System.out.println(" id : " + svo.getId());
			System.out.println(" passwd : " + svo.getPasswd());
			System.out.println(" username : " + svo.getUsername());
			System.out.println(" snum : " + svo.getSnum());
			System.out.println(" depart : " + svo.getDepart());
			System.out.println(" mobile : " + svo.getMobile());
			System.out.println(" email : " + svo.getEmail());
		}
		System.out.println("----------------------------------");
	}
	
	@Test
	public void testAddMember() throws Exception {
		String strID = "JUnit1";
		StudentVO vo = new StudentVO();
		vo.setId(strID);
		vo.setPasswd(strID);
		vo.setUsername(strID);
		vo.setSnum(strID);
		memberService.addMember(vo);
		StudentVO member = memberService.readMember("JUnit1");
		System.out.println("----------------------------------");
		System.out.println(" id : " + member.getId());
		System.out.println(" passwd : " + member.getPasswd());
		System.out.println(" username : " + member.getUsername());
		System.out.println(" snum : " + member.getSnum());
		System.out.println(" depart : " + member.getDepart());
		System.out.println(" mobile : " + member.getMobile());
		System.out.println(" email : " + member.getEmail());
		System.out.println("----------------------------------");
	}
	
	@Test
	public void testReadMember() throws Exception {
		StudentVO member = memberService.readMember("JUnit1");
		System.out.println("----------------------------------");
		System.out.println(" id : " + member.getId());
		System.out.println(" passwd : " + member.getPasswd());
		System.out.println(" username : " + member.getUsername());
		System.out.println(" snum : " + member.getSnum());
		System.out.println(" depart : " + member.getDepart());
		System.out.println(" mobile : " + member.getMobile());
		System.out.println(" email : " + member.getEmail());
		System.out.println("----------------------------------");
	}
	
	@Test
	public void testDeleteMember() throws Exception {
		memberService.deleteMember("JUnit1");
		
		List<StudentVO> list = memberService.readMemberList();
		for (StudentVO svo : list) {
			System.out.println("----------------------------------");
			System.out.println(" id : " + svo.getId());
			System.out.println(" passwd : " + svo.getPasswd());
			System.out.println(" username : " + svo.getUsername());
			System.out.println(" snum : " + svo.getSnum());
			System.out.println(" depart : " + svo.getDepart());
			System.out.println(" mobile : " + svo.getMobile());
			System.out.println(" email : " + svo.getEmail());
		}
		System.out.println("----------------------------------");
	}
	
	@Test
	public void testUpdateMember() throws Exception {
		String strID = "JUnit1";
		String updateID = "JUnit2";
		StudentVO vo = new StudentVO();
		vo.setId(strID);
		vo.setPasswd(updateID);
		vo.setUsername(updateID);
		vo.setSnum(updateID);
		memberService.updateMember(vo);
		
		StudentVO member = memberService.readMember("JUnit1");
		System.out.println("----------------------------------");
		System.out.println(" id : " + member.getId());
		System.out.println(" passwd : " + member.getPasswd());
		System.out.println(" username : " + member.getUsername());
		System.out.println(" snum : " + member.getSnum());
		System.out.println(" depart : " + member.getDepart());
		System.out.println(" mobile : " + member.getMobile());
		System.out.println(" email : " + member.getEmail());
		System.out.println("----------------------------------");
	}
}