package org.tukorea.di.service;

import java.util.List;

import org.tukorea.di.domain.StudentVO;
import org.tukorea.di.persistence.MemberDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class MemberServiceImpl implements MemberService {

	@Autowired
	private MemberDAO memberDAO;

	public List<StudentVO> readMemberList() throws Exception {
		return memberDAO.readList();
	}

	public StudentVO readMember(String id) throws Exception {
		return memberDAO.read(id);
	}

	public void addMember(StudentVO student) throws Exception {
		memberDAO.add(student);
	}
	
	public void deleteMember(String id) throws Exception {
		memberDAO.delete(id);
	}

	public void updateMember(StudentVO student) throws Exception {
		memberDAO.update(student);
	}
}
